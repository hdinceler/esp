#!/bin/bash

BROKER="haysaf.com"
PORT=1883
TOPIC="ev/esp_roleler"

echo "MQTT dinleniyor: $TOPIC"

mosquitto_sub -h "$BROKER" -p "$PORT" -t "$TOPIC" -v
