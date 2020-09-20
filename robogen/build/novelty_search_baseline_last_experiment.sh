echo "Finishing novelty baseline experiment set 11"
	for x in {2..10}
	do
		echo "Running experiment 11:($x/10)."
		./robogen-server 8011 &>/dev/null &
		./robogen-evolver $RANDOM noveltyResults/baseline/Experiment11/novelty_output11 ../projectSimulations/novelty_search/evolConf11.txt --save-all
		echo "Experiment 11:($x/10) finished."
	done
echo "Experiment set 11 finished..."