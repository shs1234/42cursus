FROM python:3

WORKDIR /usr/src/app

ENV PYTHONDONTWRITEBYTECODE 1
ENV PYTHONUNBUFFERED 1
#
#RUN apk update \
#    && apk add postgresql-dev gcc python3-dev musl-dev zlib-dev jpeg-dev dumb-init

COPY . /usr/src/app

# Install dependencies

#RUN pip install pip==21.0.1
RUN pip install --upgrade pip setuptools
RUN pip install -r requirements.txt