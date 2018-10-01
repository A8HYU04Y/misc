const blessed = require('blessed');

const msgBox= blessed.textarea({
shrink:true,
parent:null,
width:'45%',
height:'12%',
bottom:2,
style:{
  bg:'black',
  fg:'white'
},


left:1,

tags:true,

});
let self={
  msgBox: msgBox,
  screen:null,
 // parent:null,
  input:()=>{
  	msgBox.readInput();
  	//screen.render();
  }

}
module.exports=self;
//console.log(module.exports );

