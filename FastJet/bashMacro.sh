
start_date=$(date +%x)
start_time=$(date +%X)


# Primero definimos los parámetros de entrada.
PttMM=~/T/FastJet/Simulacion.cc	# Path to the Master Macro (pttMM).
PttOrFD=~/T/FastJet/root	# Path to the Output root Files Directory (PttOrFD).


pOF=1.root  # previous Output File (pOF).
fOF=$pOF  # final Output File (fOF).
ppTHM=pTHatMin\ =\ 1	# previous pT Hat Minimum (ppTHM).
fpTHM=$ppTHM	# final pT Hat Minimum (fpTHM).


# Ahora corremos el macro para todos los pT Hat Minimum.. Así aumentamos la estadística.
cd /home/saksevul/T/FastJet
for pTHM in {1..5}	# Ciclo sobre: root Files List (rFL).
do
  sed -i "s/$pOF/$pTHM.root/g" $PttMM
	sed -i "s/$ppTHM/pTHatMin\ =\ $pTHM/g" $PttMM	# Cabiamos el valor del pTHatMin.
  make Simulacion && ./Simulacion # A CORRER ESA MADRE!
  pOF=$pTHM.root
	ppTHM=pTHatMin\ =\ $pTHM
done
cd

# Esta siguiente parte es para regresar al código a su estado original.
sed -i "s/$pOF/$fOF/g" $PttMM
sed -i "s/$ppTHM/$fpTHM/g" $PttMM


# Finalmete juntamos todos los archivos root de salida, correspondientes a cada JCA, (1 por cada root File).
for JCA in ak5FJ #ak7PF kt4PF kt6PF	# Hago en ciclo sobre los Jet Clustering Algorithms (JCAs).
do
	rm $PttOrFD/$JCA.root	# Eliminamos los archivos viejos, pues serán remplazados.
	hadd $PttOrFD/$JCA.root $PttOrFD/.$JCA-*.root	# Creamos un único archivo root para cada JCA.
	rm $PttOrFD/.$JCA-*.root	# Eliminamos permanentemente los archivos que ya no necesitaremos más.
done


printf "\n\n Inició  el  $start_date, a las  $start_time.\n\n Terminó el  $(date +%x), a las  $(date +%X).\n\n"
