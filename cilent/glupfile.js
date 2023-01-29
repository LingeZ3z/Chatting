// 获取依赖
var gulp = require('gulp'),
    childProcess = require('child_process'),
    electron = require('electron');
// 创建 gulp 任务
gulp.task('run_Electron-test', function () {
    childProcess.spawn(electron, ['.'], { stdio: 'inherit' });
});