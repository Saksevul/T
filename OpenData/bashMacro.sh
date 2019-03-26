
start_date=$(date +%x)
start_time=$(date +%X)


# Primero definimos los parámetros de entrada.
PttrFL=~/CMS_1.3.0/CMS_Run2011A/Jet_AOD_12Oct2013-v1_20000/rootFilesList	# Path to the root Files List (pttrFL).
PttMM=~/T/OpenData/Analisis.C	# Path to the Master Macro (pttMM).
PttOrFD=~/T/OpenData/Jet_20000	# Path to the Output root Files Directory (PttOrFD).


prF=0001.root	# previous root File (prF).
pJCA=ak5	# previous Jet Clustering Algorithm (pJCA).
frF=$prF	# final root File (prF).
fJCA=$pJCA	# final Jet Clustering Algorithm (fJCA).


# Ahora corremos el macro para todos los archivos. Así aumentamos la estadística.
for rF in $(cat $PttrFL)	# Ciclo sobre: root Files List (rFL).
do
	sed -i "s/$prF/$rF/g" $PttMM	# Cambiamos el root File de entrada del Master Macro (MM).
	for JCA in ak5 ak7 kt4 kt6	# Hago en ciclo sobre los Jet Clustering Algorithms (JCAs).
	do
		sed -i "s/$pJCA/$JCA/g" $PttMM	# Cambiamos el JCA de análisis.
		root -l -q $PttMM	# Corremos el Master Macro (MM).
		pJCA=$JCA
	done
	prF=$rF
done


# Esta siguiente parte es para regresar al código a su estado original.
sed -i "s/$rF/$frF/g" $PttMM
sed -i "s/$JCA/$fJCA/g" $PttMM


# Finalmete juntamos todos los archivos root de salida, correspondientes a cada JCA, (1 por cada root File).
for JCA in ak5PF ak7PF kt4PF kt6PF	# Hago en ciclo sobre los Jet Clustering Algorithms (JCAs).
do
	rm $PttOrFD/$JCA.root	# Eliminamos los archivos viejos, pues serán remplazados.
	hadd $PttOrFD/$JCA.root $PttOrFD/$JCA-*.root	# Creamos un único archivo root para cada JCA.
	rm $PttOrFD/$JCA-*.root	# Eliminamos permanentemente los archivos que ya no necesitamos.
done


printf "\n\n Inició  el  $start_date, a las  $start_time.\n\n Terminó el  $(date +%x), a las  $(date +%X).\n\n"
