#!/bin/bash

DIR="$1"
SHIFT="$2"

if [ -z "$DIR" ] || [ -z "$SHIFT" ]; then
    echo "Usage: $0 <directory> <shift>"
    exit 1
fi

SHIFT_EN=$((SHIFT % 26))
SHIFT_RU=$((SHIFT % 33))

LOWER_EN="abcdefghijklmnopqrstuvwxyz"
UPPER_EN="ABCDEFGHIJKLMNOPQRSTUVWXYZ"

LOWER_RU="абвгдеёжзийклмнопрстуфхцчшщъыьэюя"
UPPER_RU="АБВГДЕЁЖЗИЙКЛМНОПРСТУФХЦЧШЩЪЫЬЭЮЯ"

LOWER_EN_SHIFTED="${LOWER_EN:$SHIFT_EN}${LOWER_EN:0:$SHIFT_EN}"
UPPER_EN_SHIFTED="${UPPER_EN:$SHIFT_EN}${UPPER_EN:0:$SHIFT_EN}"

LOWER_RU_SHIFTED="${LOWER_RU:$SHIFT_RU}${LOWER_RU:0:$SHIFT_RU}"
UPPER_RU_SHIFTED="${UPPER_RU:$SHIFT_RU}${UPPER_RU:0:$SHIFT_RU}"

find "$DIR" -type f -name "*.txt" | while read file; do
    tr "$LOWER_EN$UPPER_EN$LOWER_RU$UPPER_RU" "$LOWER_EN_SHIFTED$UPPER_EN_SHIFTED$LOWER_RU_SHIFTED$UPPER_RU_SHIFTED" < "$file" > "$file.tmp"
    mv "$file.tmp" "$file"
done
