#!bin/awk -f
BEGIN {
	CORRECT=0 
	WRONG=0
}
{
	if($1<0 && $1>12){
		WRONG++
		print "wrong format in line "(WRONG+CORRECT)
	}
	else if($2<0 && $2>59){
		WRONG++
		print "wrong format in line "(WRONG+CORRECT)
	}

	else if($3~"AM"){ 
		print $1":"$2
		CORRECT++	
	}
	else if($3~"PM"){
		print ($1+12)":"$2
		CORRECT++	
	}
	else{ 
		WRONG++
		print "wrong format in line "(WRONG+CORRECT)
		
	}
}
END {print "Total number of correctly formatted records is " CORRECT}

