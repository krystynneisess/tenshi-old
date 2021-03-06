var root = process.argv[2];
var misc = require ( root + '/misc.js' );
var angelic = require ( root + '/main.js' );

// This used to be fib50
// Turns out that doesn't fit in 32 bits.
var fib25 = 0;

function compile_and_run ( text ) {
  var vm = angelic.make ( );
  vm.set_common_defs_path(root + '/../common_defs');
  vm.add_library ( 'core', [
    vm.make_exfn ( 0, 'print', misc.print ),
    vm.make_exfn ( 1, 'setFib25', function ( val ) {
      fib25 = val;
      } ),
    ] );
  vm.load_text ( text );
  vm.start_main ( );
  vm.set_evaluation_rate ( 10000, 0.01 );
  return vm;
  }

var code = '' +
'fib = fn (n):\n' +
'    n = n - 1\n' +
'    a = 0\n' +
'    b = 1\n' +
'    while n != 0:\n' +
'        temp = a + b\n' +
'        a = b\n' +
'        b = temp\n' +
'        n = n - 1\n' +
'    return b\n' +
'main = fn:\n' +
'    x = 25\n' +
'    print (x)\n' +
'    fib25 = fib (x)\n' +
'    print (fib25)\n' +
'    setFib25 (fib25)\n' +
'';

compile_and_run ( code );

setTimeout ( function ( ) {
  if ( fib25 == 75025 ) {
    process.exit ( 0 );
    }
  else {
    misc.print('fib25 set incorrectly!');
    misc.print('fib25 = ' + fib25);
    process.exit ( 1 );
    }
  }, 1 );
