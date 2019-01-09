#!/bin/bash
make practica4
for f in programs/*.in
do
	name=${f:9:-3}
	echo "Generando output para el test $name..."
	./prueba_TS $f output/$name.out
done