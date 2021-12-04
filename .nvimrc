nnoremap <F2> :FSHere<CR> "Switch between .cpp/.hpp files
call quickui#menu#clear('P&roject')
" dgmrc-io-ex
call quickui#menu#install('P&roject', [
            \ [ 'make(&debug)', ':AsyncRun . ./build.sh && build_debug' ],
            \ [ 'run(debu&g)', ':AsyncRun . ./build.sh && run_debug' ],
            \ [ '&make(release)', ':AsyncRun . ./build.sh && build_release' ],
            \ [ '&run(release)', ':AsyncRun . ./build.sh && run_release' ],
            \ [ '&clean-project', ':AsyncRun . ./build.sh && clean' ],
            \ [ "--", '' ],
            \ [ "l&ibc-help", 'call LibcSH()' ],
            \ [ "libc-help-under-curs&or", 'call LibcSHUC()' ],
            \ [ "--", '' ],
            \ [ '&extract-variable', ":call ExtractVariable()" ],
            \ [ 'e&xtract-method', ":call ExtractMethod()" ],
            \ ], 5000)
