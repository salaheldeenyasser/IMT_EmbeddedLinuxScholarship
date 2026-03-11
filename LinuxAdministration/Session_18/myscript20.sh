#!/bin/bash

echo "=== FILES ==="
for item in *; do
    if [ -f "$item" ]; then
        echo "$item"
    fi
done

echo ""
echo "=== DIRECTORIES ==="
for item in *; do
    if [ -d "$item" ]; then
        echo "$item"
    fi
done
