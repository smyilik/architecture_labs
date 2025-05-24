from django.db import models


class Nargile(models.Model):
    name = models.CharField(max_length=30, null=True)
    bowl_type = models.CharField(max_length=30, null=True)
    bowl_material = models.CharField(max_length=30, null=True)
    tobacco = models.CharField(max_length=30, null=True)
    years_of_usage = models.CharField(max_length=30, null=True)
    # is_working = models.BooleanField(null=True)
    flask_volume = models.IntegerField(null=True)
