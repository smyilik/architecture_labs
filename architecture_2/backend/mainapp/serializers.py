from rest_framework import serializers


from .models import Nargile


class NargileSerializer(serializers.ModelSerializer):
   
    class Meta:
        model = Nargile
        fields = '__all__'
