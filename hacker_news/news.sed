/<a href="[^"]*" class="titlelink"/{
    s/.*href="\([^"]*\)".*class="titlelink"[^>]*>\([^<]*\)<.*/\*\*\2\*\*\n\1/
    p
    a\

}
