syntax on
set smarttab
set nu
set ts=4
set sw=4
set cindent
set mouse=a
map <C-A> : ggVG"+y
au BufNewFile * exec":call setline(1, '#include<bits/stdc++.h>')"
au BufNewFile * exec":call setline(3, 'using namespace std;')"
map <C-G> : call CR()<CR>
func! CR()
    exec "w"
    exec "!g++ -std=c++11 % -o %< && ./%<"
endfunc
:inoremap ( ()<ESC>i
:inoremap { {<CR>}<ESC>O
:inoremap [ []<ESC>i
:inoremap " ""<ESC>i
:inoremap ' ''<ESC>i
