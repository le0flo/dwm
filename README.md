# 👨‍💻 Dynamic Window Manager

Per avere la postazione più minimale, dwm era un "no brainer" in quanto personalizzazione, semplicità d'uso e in generale bellezza.
Questa repository è il risultato della mia personalizzazione del progetto.
Insieme a dwm, ho implementato altri programmi fondamentali per l'uso del sistema, come **alacritty** per il terminale e **rofi** come application launcher e **picom** come compositor delle finestre.

## Prerequisiti

**Premessa**, mi aspetto che questa guida la seguite, avendo sotto mano una installazione di arch completamente pulita.
Io personalmente per risparmiare tempo uso archinstall e ve lo consiglio.
Nel caso l'unico pacchetto da avere insieme al sistema base, è un modo per connettersi al wifi, che sia con **Network Manager** (consigliato) o con **iwd** o addirittura con **wpa_supplicant**, l'importante è che funzioni per voi.  

Prima di procedere all'installazione del window manager, dovrete installare i pacchetti necessari.
Quì avete una lista di pacchetti da installare.

```sh
sudo pacman -S wget curl git vim vi xorg-server xorg-xinit xorg-xsetroot xorg-xinput libinput libx11 libxinerama libxft webkit2gtk feh picom alacritty rofi
```

Alcuni pacchetti opzionali che io personalmente uso sono.

```sh
sudo pacman -S cifs-utils openssh imv mpv firefox keepassxc xfce4-screenshooter lxappearance matcha-gtk-theme
```

**P.S.** Se volete un prompt di bash carino e cross-platform, vi consiglio starship.

```sh
sudo pacman -S noto-fonts ttf-firacode-nerd starship
```

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

## Configurazione

Io come al solito incito alle persone di studiarsi i programmi e personalizzarseli a mano, ma capisco che non c'è sempre la voglia, parte del motivo per cui ho reso pubblica questa repo.
Perciò ecco una lista di configurazioni che uso e tengo aggiornate.

- Picom, [~/.config/picom.conf](https://files.le0nardo.dev/configs/picom.conf)

- Alacritty, [~/.config/alacritty.toml](https://files.le0nardo.dev/configs/alacritty.toml)

- Starship, [~/.config/starship.toml](https://files.le0nardo.dev/configs/starship.toml)

- Vim, [~/.vimrc](https://files.le0nardo.dev/configs/_vimrc)

- Rofi, [~/.config/rofi/config.rasi](https://files.le0nardo.dev/configs/config.rasi)

## Problemi e domande

Se avete problemi, dubbi o domande in generale sul progetto, aprite una issue nella repository.
