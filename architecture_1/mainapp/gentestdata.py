import random, string, datetime
from .models import *
from django.db import transaction
import faker
from faker import Faker


fk = Faker()

def gentestdata():
    # try:
    with transaction.atomic():
        for i in range(1000):
            newNargile = Nargile()
            newNargile.name = fk.name()
            newNargile.bowl_type = fk.random.choice(('Turk', 'Race phunnel', 'Race classic'))
            newNargile.bowl_material = fk.random.choice(('Glass', 'Silicon', 'Ceramic', 'Clay'))
            newNargile.tobacco = fk.random.choice(('Sweet', 'Sour', 'Cytrus'))
            newNargile.years_of_usage = random.randint(0, 10)
            # newNargile.is_working = random.randint(0, 1)
            newNargile.flask_volume = random.randint(3, 5)
            newNargile.save()

    print('OK gentestdata()')
