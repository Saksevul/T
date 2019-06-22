
start_date=$(date +%x) && start_time=$(date +%X)


# Primero definimos los parámetros de entrada.
PttMM=/home/saksevul/T/OpenData/Analisis.C	# Path to the Master Macro (pttMM).
PttrFL=/home/saksevul/CMS_Run2011A/BTag_20000/rootFilesList	# Path to the root Files List (pttrFL).
PttOrFD=/home/saksevul/T/OpenData/BTag_20000	# Path to the Output root Files Directory (PttOrFD).
pJT=BTag	# previous Jet Type (pJT).
	fJT=$pJT	# final Jet Type (fJT).

prF=0001.root	# previous root File (prF).
	frF=$prF	# final root File (prF).
pJCA=ak5PF	# previous Jet Clustering Algorithm (pJCA).
	fJCA=$pJCA	# final Jet Clustering Algorithm (fJCA).


for JT in BTag Jet MinBias MultiJet	# Ciclo sobre: Jet Type (JT).
do
PttrFL=$(echo $PttrFL | sed "s/$pJT\_20000/$JT\_20000/g")
PttOrFD=$(echo $PttOrFD | sed "s/$pJT\_20000/$JT\_20000/g")
sed -i "s/$pJT\_20000/$JT\_20000/g" $PttMM
	# Ahora corremos el macro para todos los archivos. Así aumentamos la estadística.
	for JCA in ak5PF # ak7PF kt4PF kt6PF	# Hago en ciclo sobre los Jet Clustering Algorithms (JCAs).
	do
		sed -i "s/$pJCA/$JCA/g" $PttMM	# Cambiamos el JCA de análisis.
		for rF in $(cat $PttrFL)	# Ciclo sobre: root Files List (rFL).
		do
			sed -i "s/$prF/$rF/g" $PttMM	# Cambiamos el root File de entrada del Master Macro (MM).
			root -l -q 2> /dev/null $PttMM	# Corremos el Master Macro (MM). (Eliminamos mensajes de error).
			prF=$rF
		done
		# Finalmete juntamos todos los archivos root de salida, correspondientes a cada JCA, (1 por cada root File).
		rm $PttOrFD/$JCA.root	# Eliminamos los archivos viejos, pues serán remplazados.
		hadd $PttOrFD/$JCA.root $PttOrFD/$JCA-*.root	# Creamos un único archivo root para cada JCA.
		rm $PttOrFD/$JCA-*.root	# Eliminamos permanentemente los archivos que ya no necesitamos.
		pJCA=$JCA
	done
	pJT=$JT
done


# Esta siguiente parte es para regresar al código a su estado original.
sed -i "s/$rF/$frF/g" $PttMM
sed -i "s/$JCA/$fJCA/g" $PttMM
sed -i "s/$JT\_20000/$fJT\_20000/g" $PttMM


	printf "\n\n Inició  el  $start_date, a las  $start_time.\n\n Terminó el  $(date +%x), a las  $(date +%X).\n\n"


exec bash # Elimina todas las variables. Pero deja el entorno ROOT activo.
