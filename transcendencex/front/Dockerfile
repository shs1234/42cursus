FROM python:3

ENV PYTHONDONTWRITEBYTECODE=1
ENV PYTHONUNBUFFERED=1

WORKDIR /usr/src/app

COPY . /usr/src/app

# Install dependencies]
RUN pip install --upgrade pip
RUN pip install -r requirements.txt