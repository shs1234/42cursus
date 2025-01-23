from django.db import models
from django.contrib.auth.models import AbstractUser
from django.utils.translation import gettext_lazy as _
from .managers import UserManager


# Create your models here.
class User(AbstractUser):
    username = models.CharField(max_length=50, blank=True)
    email = models.EmailField(_('email address'), unique=True)
    avatar = models.ImageField(upload_to='accounts/avatars/%Y/%m/%d', null=True, blank=True)

    USERNAME_FIELD = 'email'
    REQUIRED_FIELDS = []

    objects = UserManager()

    def __str__(self):
        return self.email
