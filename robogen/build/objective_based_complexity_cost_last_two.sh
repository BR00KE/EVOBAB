echo "Running last two experiments for objective search with complexity cost"
for i in {10..11} 
do
	echo "Running experiment set $i"
	for x in {1..10}
	do
		num=$(($i + 12))
		echo "Running experiment $i:($x/10)."
		./robogen-server 80$num &>/dev/null &
		./robogen-evolver $RANDOM objectiveResults/complexityCost/Experiment$i/objective_output$i ../projectSimulations/objective_based_cost/evolConf$i.txt --save-all --complexity-cost
		echo "Experiment $i:($x/10) finished."
	done
	echo "Experiment set $i finished..."
done