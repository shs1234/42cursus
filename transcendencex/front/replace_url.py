import os
import re


def replace_url_in_file(file_path, old_url, new_url):
    # 파일을 읽기 모드로 열기
    with open(file_path, 'r', encoding='utf-8') as file:
        content = file.read()

    # URL 변경
    updated_content = re.sub(old_url, new_url, content)

    # 파일을 쓰기 모드로 다시 열고 내용을 업데이트
    with open(file_path, 'w', encoding='utf-8') as file:
        file.write(updated_content)


# 환경 변수에서 백엔드 IP 읽기
backend_ip = os.environ.get('BACKEND_IP')

# 변경할 파일의 경로
js_file_path = 'myapp/static/js/main.js'  # JavaScript 설정 파일 경로
html_file_path = 'myapp/templates/login.html'  # HTML 설정 파일 경로
old_url = r'https:\/\/localhost'  # 정규 표현식 형태
old_wss = r'wss:\/\/localhost'  # WebSocket URL

# 환경 변수로 받은 IP로 URL 변경
new_url = f'https://{backend_ip}'
new_wss = f'wss://{backend_ip}'

# 파일 내 URL 변경 함수 호출
replace_url_in_file(js_file_path, old_url, new_url)
replace_url_in_file(js_file_path, old_wss, new_wss)

replace_url_in_file(html_file_path, old_url, new_url)