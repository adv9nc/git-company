while True:
    try:
        H, M, k = map(int, input("\033[0m시간, 분, 경과분을 입력하세요 : ").split())
    except:
        print("\033[31m입력이 유효하지 않습니다. 숫자는 반드시 공백으로 구분되어야 합니다.")
        continue
    M += k
    if M >= 60:
        H += M // 60
        M %= 60
    if H > 12:
        H %= 12
    print("%d:%d" % (H, M))
