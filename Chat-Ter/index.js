const blessed = require('blessed');
const prog = blessed.program();
const scr  = require('./ui/screen.js');
const box  = require('./ui/box.js');
const msgBox = require('./ui/msgBox.js');
msgBox.msgBox.parent= box.box;
scr.append(box.box);
scr.append(msgBox.msgBox);
box.screen=scr;
msgBox.screen=scr;
scr.render();
prog.key('i',(ch,key)=>{
	msgBox.input();
	scr.render();

});
prog.key('C-c',(ch,key)=>{
	prog.clear();
	return process.exit(0);
});
