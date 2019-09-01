# 0.- Guardamos la fecha y hora de inicio del macro.
start_date=$(date +%x) && start_time=$(date +%X)


# 1.- Definir los parámetros de entrada.

# Ruta al Macro Maestro (RutaMM).
RutaMM=/home/saksevul/T/OpenData/Analisis_Limits.C
# Ruta a la Lista de AOD's. (RutaLAOD).
RutaLAOD=/home/saksevul/CMS_Run2011A/BTag_20000/ListaAOD1024
# Ruta al Directorio de Archivos de Salida (RutaDAS).
RutaDAS=/home/saksevul/T/OpenData/BTag_20000
# inicial Tipo de AOD (iTAOD).
iTAOD=BTag
  # previo Tipo de AOD (pTAOD).
  pTAOD=$iTAOD
# inicial Algoritmo de Reconstrucción de Jets (iARJ).
iARJ=ak5PF
  # previo Algoritmo de Reconstrucción de Jets (pARJ).
  pARJ=$iARJ
# inicial AOD (iAOD).
iAOD=0001.root
  # previo AOD (pAOD).
  pAOD=$iAOD


	# 2.- Realizar ciclos for para aumentar la estadística.

	# Ciclo for sobre Jet Type (TAOD).
	for TAOD in BTag Jet MinBias MultiJet
	do
	  # Modificamos RutaLAOD para utilizar el TAOD actual.
	  RutaLAOD=$(echo $RutaLAOD | sed "s/$pTAOD\_20000/$TAOD\_20000/g")
	  # Modificamos RutaDAS para utilizar el TAOD actual.
	  RutaDAS=$(echo $RutaDAS | sed "s/$pTAOD\_20000/$TAOD\_20000/g")
	  # Modificamos el Master Macro (MM) para utilizar el TAOD actual.
	  sed -i "s/$pTAOD\_20000/$TAOD\_20000/g" $RutaMM
	  # Ciclo for sobre los Algoritmos de Reconstrucción de Jets (ARJ).
	  for ARJ in ak5PF ak7PF kt4PF kt6PF
	  do
	    # Modificamos el MM para utilizar el ARJ actual.
	    sed -i "s/$pARJ/$ARJ/g" $RutaMM
	    # Ciclo for sobre los archivos en root Files List (AODL).
	    for AOD in $(cat $RutaLAOD)
	    do
	      # Cambiar el root File de entrada en el Master Macro (MM).
	      sed -i "s/$pAOD/$AOD/g" $RutaMM
	      # Correr el Master Macro (MM). (Sin mensajes de error).
	      root -l -q 2> /dev/null $RutaMM
	      # Redefinimos pAOD para el siguiente ciclo.
	      pAOD=$AOD
	    done  # Fin del ciclo for para AOD.
	    # Eliminamos los archivos viejos, pues serán remplazados.
	    rm $RutaDAS/$ARJ\_Limits.root
	    # Creamos un único archivo root para el ARJ actual.
	    hadd $RutaDAS/$ARJ\_Limits.root $RutaDAS/$ARJ\_Limits-*.root
	    # Eliminamos permanentemente los archivos individuales.
	    rm $RutaDAS/$ARJ\_Limits-*.root
	    # Redefinios pARJ para el siguiente ciclo for.
	    pARJ=$ARJ
	  done  # Fin del ciclo for para ARJ.
	  # Redefinimos pTAOD para el siguiente ciclo.
	  pTAOD=$TAOD
	done  # Fin del ciclo for para TAOD.


# Esta siguiente parte es para regresar al código a su estado inicial.
sed -i "s/$AOD/$iAOD/g" $RutaMM
sed -i "s/$ARJ/$iARJ/g" $RutaMM
sed -i "s/$TAOD\_20000/$iTAOD\_20000/g" $RutaMM


# 4.- Mostrar la fecha y hora de inicio y término de este macro.
printf "\n\n Inició  el  $start_date, a las  $start_time.\n\n Terminó el  $(date +%x), a las  $(date +%X).\n\n"


# 5.- Eliminar todas las variables utilizadas.
exec bash
