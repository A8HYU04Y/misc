const blessed = require('blessed');
/*const scr = blessed.screen({
	smartCSR:true
});
*/
const box  = blessed.box({
  label : 'Chat',
  shrink:true,
  left:1,
  top:1,
  height:'80%',
  width:'45%',
  bottom:2,
  border:{
  	type:'line',
  	bg:'default',
  	fg:'default'
  },
  style:{
  	fg:'white',
  	bg :'grey'
  },
padding:3

});


let self={
 box:box,
 screen:null,
 foucus:()=>{
 	box.border.fg='green';
 }

}
module.exports=self;
/*
scr.append(box);
scr.render();
scr.key('C-c',(ch,key)=>{
	return process.exit(0);
})
*/