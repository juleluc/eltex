#!/bin/bash

SCRIPT_NAME=$(basename "$0")
LOG_FILE="report_${SCRIPT_NAME}.log"

PID=$$

DATETIME=$(date "+%Y-%m-%d %H:%M:%S")

echo "[$PID] $DATETIME Скрипт запущен" >> "$LOG_FILE"

MIN=30
MAX=180
GENERATE_SLEEP_TIME=$((MIN + RANDOM % (MAX - MIN + 1)))

sleep "$GENERATE_SLEEP_TIME"

TIME_TO_MINUTE=$((GENERATE_SLEEP_TIME / 60))

DATETIME=$(date "+%Y-%m-%d %H:%M:%S")

echo "[$PID] $DATETIME Скрипт завершился, работал $TIME_TO_MINUTE минут" >> "$LOG_FILE"
