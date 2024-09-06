import random

vocabulary = {
    "apple": "사과",
    "banana": "바나나",
    "grape": "포도",
    "orange": "오렌지",
    "pineapple": "파인애플",
    "watermelon": "수박",
    "strawberry": "딸기",
    "kiwi": "키위",
    "blueberry": "블루베리",
    "peach": "복숭아",
    "mango": "망고",
    "papaya": "파파야",
    "architecture": "건축",
    "pizza": "피자",
    "pasta": "파스타",
    "sushi": "초밥",
    "burger": "햄버거",
    "sandwich": "샌드위치",
    "taco": "타코",
    "curry": "카레",
    "steak": "스테이크",
    "salad": "샐러드",
    "soup": "수프",
    "sunny": "맑은",
    "cloudy": "흐린",
    "rainy": "비 오는",
    "windy": "바람 부는",
    "snowy": "눈 오는",
    "stormy": "폭풍우가 치는",
    "foggy": "안개 낀",
    "happy": "행복한",
    "sad": "슬픈",
    "angry": "화난",
    "excited": "흥분한",
    "nervous": "신경질적인",
    "tired": "피곤한",
    "relaxed": "편안한",
    "surprised": "놀라운",
    "dog": "개",
    "cat": "고양이",
    "bird": "새",
    "fish": "물고기",
    "rabbit": "토끼",
    "hamster": "햄스터",
    "turtle": "거북이",
    "horse": "말",
    "elephant": "코끼리",
    "lion": "사자",
    "tiger": "호랑이",
    "giraffe": "기린",
    "monkey": "원숭이",
    "penguin": "펭귄",
    "koala": "코알라",
    "panda": "판다",
    "kangaroo": "캥거루",
    # Add more animal-related words here
}

def vocabulary_quiz():
    score = 0
    wrong_attempts = 0
    words = list(vocabulary.keys())
    random.shuffle(words)
    
    for word in words:
        meaning = vocabulary[word]
        answer = input(f"What is the meaning of '{word}'? ")
        if answer.lower() == meaning.lower():
            print("Correct!")
            score += 1
        else:
            wrong_attempts += 1
            print(f"Wrong! The correct meaning is '{meaning}'")
            
        if wrong_attempts >= 3:
            print("You've made 3 wrong attempts. Game over.")
            break
            
    print(f"Your final score is {score}/{len(vocabulary)}")

if __name__ == "__main__":
    vocabulary_quiz()


#잘 모르는 부분은 인터넷에 찾아가보며 완성함.
