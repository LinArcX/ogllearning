nnoremap <F2> :FSHere<CR> "Switch between .cpp/.hpp files
" dgmrc-io-ex
call quickui#menu#clear('P&roject')
call quickui#menu#install('P&roject', [
            \ [ 'make(&debug)', 'lua CheckWarningsErrorsThenBuild("debug")' ],
            \ [ 'run(debu&g)', 'lua CheckWarningsErrorsThenRun("debug")' ],
            \ [ '&make(release)', 'lua CheckWarningsErrorsThenBuild("release")' ],
            \ [ '&run(release)', 'lua CheckWarningsErrorsThenRun("release")' ],
            \ [ '&clean-project', ':AsyncRun . ./build.sh && clean' ],
            \ [ "--", '' ],
            \ [ "l&ibc-help", 'call LibcSH()' ],
            \ [ "libc-help-under-curs&or", 'call LibcSHUC()' ],
            \ [ "--", '' ],
            \ [ '&extract-variable', ":call ExtractVariable()" ],
            \ [ 'e&xtract-method', ":call ExtractMethod()" ],
            \ ], 5000)

lua << EOF
local dap = require('dap')
dap.configurations.cpp = {
  {
    args = {},
    type = "lldb",
    name = "Launch",
    request = "launch",
    program = "${workspaceFolder}/build/linux/debug/app",
    cwd = '${workspaceFolder}',
    stopOnEntry = false,
    runInTerminal = false,
  },
}

function CheckWarningsErrorsThenBuild(build_type)
    local lspWECount = vim.lsp.diagnostic.get_count()
    if lspWECount > 0 then
        print("Lsp WE count is:" .. lspWECount)
        require('telescope.builtin').lsp_workspace_diagnostics()
    else
        print("Lsp WE count is:" .. lspWECount)
        if build_type == "debug" then
            vim.cmd([[
                AsyncRun . ./build.sh && build_debug
            ]])
        elseif build_type == "release" then
            vim.cmd([[
                AsyncRun . ./build.sh && build_release
            ]])
        end
    end
end

function CheckWarningsErrorsThenRun(run_type)
    local lspWECount = vim.lsp.diagnostic.get_count()
    if lspWECount > 0 then
        print("Lsp WE count is:" .. lspWECount)
        require('telescope.builtin').lsp_workspace_diagnostics()
    else
        print("Lsp WE count is:" .. lspWECount)
        if run_type == "debug" then
            vim.cmd([[
                AsyncRun . ./build.sh && run_debug
            ]])
        elseif run_type == "release" then
            vim.cmd([[
                AsyncRun . ./build.sh && run_release
            ]])
        end
    end
end
EOF
