#!/bin/bash
#
## script portscan.sh
# Script para varrer todas as portas de um host
# Autor: Luciano Domingues
# Data: 14.09.2019

## DEFINICAO DE VARIAVEIS
porta_inicio=0
porta_fim=65535
conta=0

## INICIA O TESTE NA REDE
clear
echo "*** Iniciando portscan...."
echo "==> Testando todas as portas do host $1 ..."
for porta in $(seq $porta_inicio $porta_fim)
do
	hping3 -S $1 -c 1 -p $porta 2>/dev/null | grep "SA" &>/dev/null
	# CONFIRMA SE A PORTA ESTA ABERTA
	if [ $? -eq 0 ]
	then
		echo "Porta $porta - Status [ABERTA]"
		((conta++))
	fi
done
echo "*** FIM portscan...."
echo "Foram encontradas $conta portas abertas"
exit 0