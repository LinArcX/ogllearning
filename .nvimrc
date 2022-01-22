nnoremap <silent> <A-o> :FSHere<CR>

lua << EOF
table.insert(require('command_palette').CpMenu,
  {"Project",
    { 'extract variable', ":call ExtractVariable()" },
    { 'extract method', ":call ExtractMethod()" },
    { "libc help", ':call LibcSH()' },
    { "libc help(under cursor)", ':call LibcSHUC()' },
    { 'clean project', ':AsyncRun . ./build.sh && clean' },
    { 'run(release)', ':lua CheckWarningsErrorsThenRun("release")' },
    { 'build(release)', ':lua CheckWarningsErrorsThenBuild("release")' },
    { 'run(debug)', ':lua CheckWarningsErrorsThenRun("debug")' },
    { 'build(debug)', ':AsyncRun . ./build.sh && build_debug' },
  })

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
  --local lspWECount = vim.lsp.diagnostic.get_count()
  --if lspWECount > 0 then
  --  print("Lsp WE count is:" .. lspWECount)
  --  require('telescope.builtin').lsp_workspace_diagnostics()
  --else
  --  print("Lsp WE count is:" .. lspWECount)
    if build_type == "debug" then
      vim.cmd([[
          AsyncRun . ./build.sh && build_debug
      ]])
    elseif build_type == "release" then
      vim.cmd([[
          AsyncRun . ./build.sh && build_release
      ]])
    end
  --end
end

function CheckWarningsErrorsThenRun(run_type)
  --local lspWECount = vim.lsp.diagnostic.get_count()
  --if lspWECount > 0 then
  --  print("Lsp WE count is:" .. lspWECount)
  --  require('telescope.builtin').lsp_workspace_diagnostics()
  --else
  --  print("Lsp WE count is:" .. lspWECount)
    if run_type == "debug" then
      vim.cmd([[
        AsyncRun . ./build.sh && run_debug
      ]])
    elseif run_type == "release" then
      vim.cmd([[
        AsyncRun . ./build.sh && run_release
      ]])
    end
  --end
end
EOF
