#!/bin/bash

# Nombre del archivo de salida
output_file="ssh_keys.txt"

# Verificar si el archivo de salida existe y eliminarlo
if [ -f "${output_file}" ]; then
    rm "${output_file}"
fi

# Loop a través de cada usuario en el sistema
while IFS=: read -r user _; do
    # Verificar si el usuario tiene un directorio .ssh
    ssh_dir="/home/${user}/.ssh"
    if [ -d "${ssh_dir}" ]; then
        # Loop a través de cada archivo id_rsa en el directorio .ssh
        for key_file in ${ssh_dir}/id_rsa*; do
            # Obtener el contenido de la llave y agregarlo al archivo de salida
            key_content=$(cat "${key_file}")
            echo "${user}:${key_content}" >> "${output_file}"
        done
    fi
done < /etc/passwd

# Verificar si el directorio .ssh de root existe y contiene un archivo id_rsa
root_ssh_dir="/root/.ssh"
if [ -d "${root_ssh_dir}" ]; then
    root_key_file="${root_ssh_dir}/id_rsa"
    if [ -f "${root_key_file}" ]; then
        # Obtener el contenido de la llave y agregarlo al archivo de salida
        key_content=$(cat "${root_key_file}")
        echo "root:${key_content}" >> "${output_file}"
    fi
fi
