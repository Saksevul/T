# 0.- Guardamos la fecha y hora de inicio del macro.
start_date=$(date +%x) && start_time=$(date +%X)


# 1.- Definir los parámetros de entrada.
# Macro Maestro (MM).
MM=Simulacion.cc
# Ruta al Directorio del Macro Maestro (RutaDMM).
RutaDMM=/home/saksevul/T/PYTHIA
# Ruta al Directorio de Archivos de Salida (RutaDAS) (ver y/o editar MM 2 en total).
RutaDAS=$RutaDMM/FastJet
# inicial Algoritmo de Reconstrucción de Jets (pARJ).
iARJ=ak5
  # previo Algoritmo de Reconstrucción de Jets (iARJ).
  pARJ=$iARJ
# initial pT Hat Minimum (ver y/o editar Master Macro y ciclo for pTHM, 5 en total).
ipTHM=2
  # previous pT Hat Minimum (ipTHM).
  ppTHM=$ipTHM
# initial Number of Events (ver y/o editar Master Macro, 2 en total).
iNoE=4800
  # previous Number of Events (pNoE).
  pNoE=$iNoE
  # Total Number of Events (TNoE).
  TNoE=0
# Guardamos es directorio actual de trabajo y pasamos a la RutaDMM.
pwd=$PWD && cd $RutaDMM
# previous Jet Custering Algorithm (JCA).
pJCA=\-1
  ak=\-1;  kt=1
# previous Jet Size (JS).
pJS=0.5


# 2.- Realizar los ciclos for necesarios.
# Hago en ciclo sobre los Jet Clustering Algorithms (ARJs).
for ARJ in ak5 ak7 kt4 kt6
do
  # Modificamos el MM para utilizar el ARJ actual.
  sed -i "s/$pARJ/$ARJ/g" $MM
  if [ $ARJ == 'ak5' ];  then
    sed -i "s/JCA\ \ \ \ =\ $pJCA\;/JCA\ \ \ \ =\ $ak\;/g" $MM
    sed -i "s/R\ \ \ \ \ \ =\ $pJS\;/R\ \ \ \ \ \ =\ 0.5\;/g" $MM
    # Redefinios algunos parámetros para el siguiente ciclo for.
    pARJ=ak5;    pJCA=$ak;    pJS=0.5
  elif [ $ARJ == 'ak7' ];  then
    sed -i "s/JCA\ \ \ \ =\ $pJCA\;/JCA\ \ \ \ =\ $ak\;/g" $MM
    sed -i "s/R\ \ \ \ \ \ =\ $pJS\;/R\ \ \ \ \ \ =\ 0.7\;/g" $MM
    # Redefinios algunos parámetros para el siguiente ciclo for.
    pARJ=ak7;    pJCA=$ak;    pJS=0.7
  elif [ $ARJ == 'kt4' ];  then
    sed -i "s/JCA\ \ \ \ =\ $pJCA\;/JCA\ \ \ \ =\ $kt\;/g" $MM
    sed -i "s/R\ \ \ \ \ \ =\ $pJS\;/R\ \ \ \ \ \ =\ 0.4\;/g" $MM
    # Redefinios algunos parámetros para el siguiente ciclo for.
    pARJ=kt4;    pJCA=$kt;    pJS=0.4
  elif [ $ARJ == 'kt6' ];  then
    sed -i "s/JCA\ \ \ \ =\ $pJCA\;/JCA\ \ \ \ =\ $kt\;/g" $MM
    sed -i "s/R\ \ \ \ \ \ =\ $pJS\;/R\ \ \ \ \ \ =\ 0.6\;/g" $MM
    # Redefinios algunos parámetros para el siguiente ciclo for.
    pARJ=kt6;    pJCA=$kt;    pJS=0.6
  fi
  # Ciclo sobre distintos valores de pT Hat Minimum.
  for pTHM in {2..3500..1} # initial pT Hat Minimum (ver y/o editar Master Macro y ciclo for pTHM, 5 en total).
  do
    # Modificamos el Master Macro (MM) para utilizar el AS actual.
    sed -i "s/\-$ppTHM.root/\-$pTHM.root/g" $MM
    # Cabiamos el valor del pTHatMin.
  	sed -i "s/pTHatMin\ =\ $ppTHM.0/pTHatMin\ =\ $pTHM.0/g" $MM
    # Numero de eventos en función de pTHatMin.
    # # NoE=$(awk -v pTHM=$pTHM -v iNoE=$iNoE 'BEGIN{x=iNoE*10^(-pTHM/1000); print x}')
    # NoE=$(awk -v pTHM=$pTHM -v iNoE=$iNoE 'BEGIN{x=iNoE*(10^(-pTHM/1000)-10^(-3500/1000)); print int(x)}')
    # # NoE=$(awk -v pTHM=$pTHM -v iNoE=$iNoE 'BEGIN{x=iNoE*pTHM^(-0.3); print x}')
    NoE=$(awk -v pTHM=$pTHM -v iNoE=$iNoE 'BEGIN{x=2.5*iNoE*(pTHM^(-0.1)-3500^(-0.1)); print int(x)}')
    # # NoE=$(awk -v pTHM=$pTHM -v iNoE=$iNoE 'BEGIN{x=iNoE/4.0-pTHM/12.0; print x}')
    # NoE=$(awk -v pTHM=$pTHM -v iNoE=$iNoE 'BEGIN{x=(iNoE/(14400.0))*(3500-pTHM); print int(x)}')
    # Sumamos estos Eventos al Total de Eventos.
    TNoE=$(awk -v NoE=$NoE -v TNoE=$TNoE 'BEGIN{x=TNoE+NoE; print x}')
    # Cabiamos el valor del NoE.
    sed -i "s/nEvent\ \ \ \ =\ $pNoE\;/nEvent\ \ \ \ =\ $NoE\;/g" $MM
    # A CORRER ESA MADRE!
    make -s Simulacion 2> /dev/null && ./Simulacion
    # Redefinios ppTHM para el siguiente ciclo for.
  	ppTHM=$pTHM
    # Redefinios pNoE para el siguiente ciclo for.
    pNoE=$NoE
  done  # Fin del ciclo for para pTHatMax.

  # Preparamos al MM par el siguiente ciclo for.
  sed -i "s/\-$ppTHM.root/\-$ipTHM.root/g" $MM
  sed -i "s/pTHatMin\ =\ $ppTHM.0/pTHatMin\ =\ $ipTHM.0/g" $MM
  sed -i "s/nEvent\ \ \ \ =\ $pNoE\;/nEvent\ \ \ \ =\ $iNoE\;/g" $MM
  ppTHM=$ipTHM;  pNoE=$iNoE

  # Eliminamos los archivos viejos, pues serán remplazados.
	rm $RutaDAS/$ARJ\FJ\2.root
  # Creamos un único archivo de salida para cada ARJ.
	hadd $RutaDAS/$ARJ\FJ\2.root $RutaDAS/$ARJ\FJ-*.root
  # Eliminamos los archivos individuales.
	rm $RutaDAS/$ARJ\FJ-*.root
done  # Fin del ciclo for para ARJ.


# 3.- Regresamos el MM a su estado inicial.
sed -i "s/$pARJ/$iARJ/g" $MM
sed -i "s/JCA\ \ \ \ =\ $pJCA\;/JCA\ \ \ \ =\ $ak\;/g" $MM
sed -i "s/R\ \ \ \ \ \ =\ $pJS\;/R\ \ \ \ \ \ =\ 0.5\;/g" $MM


# 4.- Volvemos al directorio anterior de trabajo.
cd $pwd


# 5.- Mostrar la fecha y hora de inicio y término de este macro.
printf "\n\n\t Eventos Totales Simulados: $TNoE.\n\n"
printf "\n\n Inició  el  $start_date, a las  $start_time.\n\n Terminó el  $(date +%x), a las  $(date +%X).\n\n\n"


# 6.- Eliminar todas las variables utilizadas.
exec bash
