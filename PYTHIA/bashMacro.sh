
start_date=$(date +%x)
start_time=$(date +%X)


# Primero definimos los parámetros de entrada.
MMN=Simulacion.cc	# Master Macro Name (MMN).
PttMMD=/home/saksevul/T/PYTHIA/  # Path to the Master Macro Directory (pttMMD).
PttOrFD=/home/saksevul/T/PYTHIA/FastJet/	# Path to the Output root Files Directory (PttOrFD).


pOF=0.root  # previous Output File (pOF).
fOF=$pOF  # final Output File (fOF).
ppTHM=pTHatMin\ =\ 0	# previous pT Hat Minimum (ppTHM).
fpTHM=$ppTHM	# final pT Hat Minimum (fpTHM).


# Ahora corremos el macro para todos los pT Hat Minimum.. Así aumentamos la estadística.
pwd=$PWD && cd $PttMMD  # Guardamos es directorio actual de trabajo y pasamos a MMD.
for pTHM in {0..3200..10}	# Ciclo sobre: root Files List (rFL).
do
  sed -i "s/$pOF/$pTHM.root/g" $PttMMD$MMN
	sed -i "s/$ppTHM/pTHatMin\ =\ $pTHM/g" $PttMMD$MMN	# Cabiamos el valor del pTHatMin.
  make Simulacion && ./Simulacion # A CORRER ESA MADRE!
  pOF=$pTHM.root
	ppTHM=pTHatMin\ =\ $pTHM
done
cd $pwd  # Regresamos al directorio anterior de tranajo.


# Esta siguiente parte es para regresar al código a su estado original.
sed -i "s/$pOF/$fOF/g" $PttMMD$MMN
sed -i "s/$ppTHM/$fpTHM/g" $PttMM$MMN


# Finalmete juntamos todos los archivos root de salida, correspondientes a cada JCA, (1 por cada root File).
for JCA in ak5FJ #ak7PF kt4PF kt6PF	# Hago en ciclo sobre los Jet Clustering Algorithms (JCAs).
do
	rm $PttOrFD/$JCA.root	# Eliminamos los archivos viejos, pues serán remplazados.
	hadd $PttOrFD/$JCA.root $PttOrFD/$JCA-*.root	# Creamos un único archivo root para cada JCA.
	# rm $PttOrFD/$JCA-*.root	# Eliminamos permanentemente los archivos que ya no necesitaremos más.
done


printf "\n\n Inició  el  $start_date, a las  $start_time.\n\n Terminó el  $(date +%x), a las  $(date +%X).\n\n"
