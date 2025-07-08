#!/bin/bash

# Check if file was passed
if [ -z "$1" ]; then
    echo "Usage: $0 <file.xpm>"
    exit 1
fi

# Input and output files
input="$1"
output="${1%.xpm}.xpm42"

# Read all lines except the first two and clean them
mapfile -t lines < <(tail -n +3 "$input" | sed -E 's/^"//; s/",?$//; s/,$//')

# Remove "};" do final da última linha, se existir
last_index=$((${#lines[@]} - 1))
lines[$last_index]=$(echo "${lines[$last_index]}" | sed 's/"};$//')

# Escreve no arquivo de saída com "!XPM42" no topo
{
    echo "!XPM42"
    for line in "${lines[@]}"; do
        echo "$line"
    done
} > "$output"

echo "Processed file saved as: $output"