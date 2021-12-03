"-------------- Key-mapping ------------""
" F2-F11 are free
nnoremap <F2> :FSHere<CR> "Switch between .cpp/.hpp files

"------------- vim-quickui settings  ------------------"
let s:clean = "ls; \n"
let s:update = "update | w |"

"coiustrpfs
call quickui#menu#install('&Debugging', [
            \ [ "&continue\tF(5)", 'call feedkeys("\<Plug>VimspectorContinue")' ],
            \ [ "step-&over\tF(6)", 'call feedkeys("\<Plug>VimspectorStepOver")' ],
            \ [ "step-&into\tF(7)", 'call feedkeys("\<Plug>VimspectorStepInto")' ],
            \ [ "step-o&ut\tF(8)", 'call feedkeys("\<Plug>VimspectorStepOut")' ],
            \ [ "&stop\tF(9)", 'call feedkeys("\<Plug>VimspectorStop")' ],
            \ [ "&toggle-breakpoint\tF(10)", 'call feedkeys("\<Plug>VimspectorToggleBreakpoint")' ],
            \ [ "&pause\tShift-p", 'call feedkeys("\<Plug>VimspectorPause")' ],
            \ [ "&restart\tShift-r", 'call feedkeys("\<Plug>VimspectorRestart")' ],
            \ [ "clo&se-debugger\tShift-s", ':call vimspector#Reset()' ],
            \ ], 5000)

"rutnpm
call quickui#menu#install('&Test', [
            \ [ "&run", 'GTestRun' ],
            \ [ "run-&under-cursor", 'GTestRunUnderCursor' ],
            \ [ "&toggle-enable", 'GTestToggleEnabled' ],
            \ [ "&next", 'GTestNext' ],
            \ [ "&previous", 'GTestPrev' ],
            \ [ "ju&mp-to-test", 'GTestJump' ],
            \ ], 5001)


call quickui#menu#clear('P&roject')
" dgmrc--ex--vfps--b
call quickui#menu#install('P&roject', [
            \ [ 'make(&debug)', s:update.':AsyncRun . ./build.sh && build_debug' ],
            \ [ 'run(debu&g)', s:update.':AsyncRun . ./build.sh && run_debug' ],
            \ [ '&make(release)', s:update.':AsyncRun . ./build.sh && build_release' ],
            \ [ '&run(release)', s:update.':AsyncRun . ./build.sh && run_release' ],
            \ [ '&clean-project', s:update.':AsyncRun . ./build.sh && clean' ],
            \ [ "--", '' ],
            \ [ '&clean', s:update.'call HTerminal(0.4, 300.0, "'. s:clean .'")' ],
            \ [ "--", '' ],
            \ [ "l&ibc-help", 'call LibcSH()' ],
            \ [ "libc-help-under-curs&or", 'call LibcSHUC()' ],
            \ ], 5002)

"casmgn--pd--eb--xfoiat
call quickui#menu#install('C&oc', [
            \ [ "&config", 'CocConfig' ],
            \ [ "code-&action", 'exec "normal \<Plug>(coc-codeaction)"' ],
            \ [ "codeaction-&selected", 'exec "normal \<Plug>(coc-codeaction-selected)"' ],
            \ [ "co&mmand", 'call feedkeys("\<Plug>(coc-command)")' ],
            \ [ "dia&gnostics", 'exec "normal \<Plug>(coc-diagnostics)"' ],
            \ [ "cha&nnel-output", 'CocCommand workspace.showOutput' ],
            \ [ "--", '' ],
            \ [ "im&plementation", 'call feedkeys("\<Plug>(coc-implementation)")' ],
            \ [ "&definition", 'call feedkeys("\<Plug>(coc-definition)")' ],
            \ [ "--", '' ],
            \ [ "&enable", 'CocEnable' ],
            \ [ "disa&ble", 'CocDisable' ],
            \ [ "--", '' ],
            \ [ "e&xtensions", ':CocList extensions' ],
            \ [ "&fix-current", 'exec "normal \<Plug>(coc-fix-current)"' ],
            \ [ "f&ormat-selected", 'exec "normal \<Plug>(coc-format-selected)"' ],
            \ [ "&info", 'CocInfo' ],
            \ [ "inst&all", 'exec "noraml \<Plug>(coc-install)"' ],
            \ [ "lis&t", ':CocList' ],
            \ [ "log", ':CocOpenLog' ],
            \ [ "outline", ':CocList outline' ],
            \ [ "rename", 'exec "noraml \<Plug>(coc-rename)"' ],
            \ [ "restart", 'CocRestart' ],
            \ [ "references", 'exec "noraml \<Plug>(coc-references)"' ],
            \ [ "type-definition", 'exec "noraml \<Plug>(coc-type-definition)"' ],
            \ ], 5003)
