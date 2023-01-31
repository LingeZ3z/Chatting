var electron = require('electron');

var app=electron.app;
var BrowserWindow = electron.BrowserWindow;

var mainWindow = null;

app.on('ready',()=>{
    mainWindow = new BrowserWindow({
        width:640,
        height:480,
        webprefrences:{nodeIntegration:true}});
    mainWindow.loadFile('index.html');
    mainWindow.on('closed',()=>{
        mainWindow=null;
    })
})