#!/bin/bash

src_dir="../textures"
out_dir="../texture_xpm"

# Encontra todos os arquivos .xpm dentro de textures e subpastas
find "$src_dir" -type f -name "*.xpm" | while read -r input; do
    # Caminho relativo do arquivo a partir de textures/
    relative_path="${input#$src_dir/}"
    
    # Remove extensão .xpm e troca por .xpm42
    output_path="${relative_path%.xpm}.xpm42"
    
    # Caminho completo para salvar
    full_output="$out_dir/$output_path"
    
    # Cria o diretório de saída, se necessário
    mkdir -p "$(dirname "$full_output")"

    # Lê e processa o conteúdo como antes
    mapfile -t lines < <(tail -n +3 "$input" | sed -E 's/^"//; s/",?$//; s/,$//')

    last_index=$((${#lines[@]} - 1))
    lines[$last_index]=$(echo "${lines[$last_index]}" | sed 's/"};$//')

    {
        echo "!XPM42"
        for line in "${lines[@]}"; do
            echo "$line"
        done
    } > "$full_output"

    echo "✔️ Processed: $input → $full_output"
done
