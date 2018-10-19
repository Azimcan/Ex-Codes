var array = Array(20);
var rnd;

for (var i = 0; i < array.length;) {
	rnd = Math.round(Math.random()*19+1);
	for (var j = 0; j < array.length; j++) {
		if ( array[j] === rnd ) {
			break;
		}
		if ( j === array.length - 1 ) {
			array[i] = rnd;
			i++;
		}
	}
}

console.log( array );
console.log( array.sort(function(a, b){return a-b}) );

console.log( array.pop() );
console.log( array.pop() );

array.push(1, 2, 3, 4);

console.log( array );
console.log( array.sort(function(a, b){return a-b}) );
