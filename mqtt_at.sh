#!/bin/bash

BROKER="haysaf.com"
PORT=1883
TOPIC="ev/esp_roleler"

mosquitto_pub -h "$BROKER" -p "$PORT" -t "$TOPIC" "$@"
