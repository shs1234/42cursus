from django.shortcuts import render

def index(request):
    return render(request, 'index.html')

def main_content(request):
    return render(request, 'main.html')

def login_content(request):
    return render(request, 'login.html')

def list_content(request):
    return render(request, 'list.html')

def local_2p(request):
    return render(request, '2pgame.html')

def local_4p(request):
    return render(request, '4pgame.html')

def index(request, room_id=None):
    context = {}
    if room_id is not None:
        context['room_id'] = room_id
    return render(request, 'index.html', context)