#!/bin/bash
echo "Starting objective_based experiments"
echo "------------------------------------"
trap "exit" INT TERM ERR
trap "kill 0" EXIT
for i in {0..9} 
do
	echo "Running experiment set $i"
	for x in {1..10}
	do
		echo "Running experiment $i:($x/10)."
		./robogen-server 800$i &>/dev/null &
		./robogen-evolver $RANDOM results/Experiment$i/novelty_output$i ../projectSimulations/novelty_search/evolConf$i.txt --save-all &>/dev/null &
		BACK_PID=$!
		wait $BACK_PID
		echo "Experiment $i:($x/10) finished."
	done
	echo "Experiment set $i finished..."
done
wait
for i in {10..11} 
do
	echo "Running experiment set $i"
	for x in {1..10}
	do
		echo "Running experiment $i:($x/10)."
		./robogen-server 80$i &>/dev/null &
		./robogen-evolver $RANDOM results/Experiment$i/novelty_output$i ../projectSimulations/novelty_search/evolConf$i.txt --save-all &>/dev/null &
		BACK_PID=$!
		wait $BACK_PID
		echo "Experiment $i:($x/10) finished."
	done
	echo "Experiment set $i finished..."
done
wait
echo "Successfully completed all experiments"
zip results.zip results/*