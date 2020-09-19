echo "Running novelty baseline experiment set 10"
	for x in {7..10}
	do
		echo "Running experiment 10:($x/10)."
		./robogen-server 8010 &>/dev/null &
		./robogen-evolver $RANDOM noveltyResults/baseline/Experiment10/novelty_output10 ../projectSimulations/novelty_search/evolConf10.txt --save-all
		echo "Experiment 10:($x/10) finished."
	done
echo "Experiment set 10 finished..."
echo "Finishing novelty baseline experiment set 11"
	for x in {2..7}
	do
		echo "Running experiment 11:($x/7)."
		./robogen-server 8011 &>/dev/null &
		./robogen-evolver $RANDOM noveltyResults/baseline/Experiment11/novelty_output11 ../projectSimulations/novelty_search/evolConf11.txt --save-all
		echo "Experiment 11:($x/7) finished."
	done
echo "Experiment set 11 finished..."