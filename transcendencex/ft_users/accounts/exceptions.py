from rest_framework.exceptions import APIException

class EmptyUsernameException(APIException):
    status_code = 422
    default_detail = 'Username cannot be empty.'
    default_code = 'username_empty'

class NonAlphanumericUsernameException(APIException):
    status_code = 422
    default_detail = 'Username must be alphanumeric.'
    default_code = 'username_non_alphanumeric'

class UsernameAlreadyExistsException(APIException):
    status_code = 409
    default_detail = 'Username already exists.'
    default_code = 'username_exists'