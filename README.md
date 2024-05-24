# 👨‍💻 Dynamic Window Manager

Per avere la postazione più minimale, dwm era un "no brainer" in quanto personalizzazione, semplicità d'uso e in generale bellezza.
Questa repository è il risultato della mia personalizzazione del progetto.
Insieme a dwm, ho implementato altri programmi fondamentali per l'uso del sistema, come **alacritty** per il terminale e **rofi** come application launcher e **picom** come compositor delle finestre.

Per questi programmi e altro, le configurazioni [si trovano tutte quì](https://files.le0nardo.dev/configs).

## Installazione

Per scaricare il codice, clona la repository con git.

```sh
git clone https://github.com/le0flo/dwm.git
```

Successivamente, entra nella repository scaricata ed esegui il seguente comando.

```sh
cd dwm
sudo make clean install
```

Il comando precedente dovrebbe aver installato dwm nel sistema. Per eseguirlo con **xinit**, inserire il seguente codice nel file **.xinitrc** nella cartella home del vostro utente.

```sh
# Avvia il compositor ed imposta lo sfondo, poi apre dwm

picom -b && feh --no-fehbg --bg-fill "/home/user/.config/backgrounds/bg.jpg"
exec dwm
```

Per avviare **xinit** al login dell'utente, inserite questo snippet di codice nel file **.bash_profile** nella cartella home del vostro utente.

```sh
# Avvia X11

if [[ -z $DISPLAY ]] && [[ $(tty) = /dev/tty1 ]]; then
	startx
fi
```
