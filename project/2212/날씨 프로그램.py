import requests
import json
from datetime import datetime, timedelta

# 기상청 API 정보를 설정합니다.
API_KEY = 'c2guMx6ZPCUsoc7PHmp6hc%2BvtIWcZzW8ske17KFM8NfVVTW2sVU9NnsSkgxSObXog96ZL5sIg285xOwvc1av0A%3D%3D'  # 발급받은 API 키를 입력하세요.
SERVICE_URL = 'http://apis.data.go.kr/1360000/VilageFcstInfoService/getVilageFcst'
DATE_FORMAT = '%Y%m%d%H%M'

# 날짜 및 시간 설정 (오늘 날짜와 시간을 기준으로 요청)
now = datetime.now()
base_date = now.strftime('%Y%m%d')  # 'YYYYMMDD' 형식
base_time = (now - timedelta(hours=1)).strftime('%H%M')  # 한 시간 전 'HHMM' 형식

# 요청 파라미터 설정
params = {
    'ServiceKey': API_KEY,
    'pageNo': '1',
    'numOfRows': '10',
    'dataType': 'JSON',
    'base_date': base_date,
    'base_time': base_time,
    'nx': '60',  # 경도 좌표
    'ny': '127',  # 위도 좌표
}

# API 요청 보내기
response = requests.get(SERVICE_URL, params=params)

# 응답 확인 및 데이터 추출
if response.status_code == 200:
   data = response.json()
   items = data['response']['body']['items']['item']
   for item in items:
        print(f"Category: {item['category']}, Value: {item['fcstValue']}")
else:
    print(f"Error: {response.status_code}")