$(document).ready(function(){
	$('#button').on('click', function() {
		//alert("Test");
	})
	
	
});

function outputUpdate(interval) {
	if(interval == 0){
		$('#interval').text("Off");
	}
	else{
		$('#interval').text(interval + " s");
	}
}