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
# Arch linux

sudo pacman -S wget curl git vim xorg-server xorg-xinit xorg-xinput libinput base-devel libx11 libxinerama libxft feh picom alacritty rofi

# Void linux

sudo xbps-install wget curl git vim xorg-server xinit xinput libinput base-devel libX11-devel libXft-devel libXinerama-devel feh picom alacritty rofi
```

Alcuni pacchetti opzionali che io personalmente uso sono.

```sh
# Arch linux

sudo pacman -S unzip zip cifs-utils openssh imv mpv htop firefox keepassxc xfce4-screenshooter lxappearance papirus-icon-theme

# Void linux

sudo xbps-install unzip zip cifs-utils openssh imv mpv htop firefox keepassxc xfce4-screenshooter lxappearance papirus-icon-theme
```

Se volete un prompt di bash carino e cross-platform, vi consiglio starship.

```sh
# Arch linux

sudo pacman -S noto-fonts ttf-firacode-nerd starship

# Void linux

sudo xbps-install noto-fonts-ttf noto-fonts-emoji font-firacode starship
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

Per Void Linux, bisogna modificare il file `config.mk` nella seguente maniera.

1. Inserire alla fine del file `FREETYPEINC = ${X11INC}/freetype2`
2. Cambiare `X11INC = usr/X11R6/include` a `X11INC = usr/X11R6/include`
3. Cambiare `X11LIB = usr/X11R6/lib` a `X11LIB = usr/X11R6/lib`

# Configurazione

Il comando precedente dovrebbe aver installato dwm nel sistema. Per eseguirlo con **xinit**, inserire il seguente codice nel file `~/.xinitrc`.

```sh
# Avvia compositor, sfondo, orologio e dwm

# Su alcuni pc si può sfruttare un compositor personalizzato, per finestre dai bordi rotondi e dagli sfondi trasparenti.
# Rimuovi il commento per abilitare picom.
#picom -b

# Crea la cartella /usr/share/backgrounds e spostaci tutti i wallpapers che desideri, poi per averli metti alla fine il nome dell'immagine.
# Rimuovi il commento per avere lo sfondo.
#feh --no-fehbg --bg-fill "/usr/share/backgrounds/bg.jpg"

# Crea la cartella /usr/share/dwm e crea il file time.sh, che puoi configurare in modo un messaggio personalizzato sulla barra del wm.
# Rimuovi il commento per visualizzare l'orario.
#/usr/share/dwm/time.sh >> /dev/null 2>&1 &

exec dwm
```

Per avviare **xinit** al login dell'utente, inserite questo snippet di codice nel file `~/.bash_profile`.

```sh
# Avvia X11

if [[ -z $DISPLAY ]] && [[ $(tty) = /dev/tty1 ]]; then
	startx
fi
```

Per risolvere alcuni problemi con programmi (e.g. IntelliJ IDEA), esportate la variabile di ambiente nel file `~/.bashrc`.

```sh
# Variabili di ambiente

export STARSHIP_CONFIG=~/.config/starship/starship.toml
export _JAVA_AWT_WM_NONREPARENTING=1
```

Per usare il prompt custom di starship con la shell bash, inserite nel file `~/.bashrc`.

```sh
# Starship

eval "$(starship init bash)"
```

Alcuni alias utili per miglioramenti nell'esperienza di utilizzo, da inserire nel file `~/.bashrc`.

```sh
# Aliases

alias ls='ls --color=auto'
alias ll='ls --color=auto -al'
alias grep='grep --color=auto'
alias ssh='TERM=xterm-256color ssh'
alias shutdown='shutdown -h now'
alias battery='upower -i $(upower -e | grep "BAT")'
```

Io come al solito incito alle persone di studiarsi i programmi e personalizzarseli a mano, ma capisco che non c'è sempre la voglia, parte del motivo per cui ho reso pubblica questa repo.
Perciò ecco una lista di configurazioni che uso e tengo aggiornate.

- Picom, [`~/.config/picom/picom.conf`](https://files.le0nardo.dev/configs/picom.conf)

- Alacritty, [`~/.config/alacritty/alacritty.toml`](https://files.le0nardo.dev/configs/alacritty.toml)

- Starship, [`~/.config/starship/starship.toml`](https://files.le0nardo.dev/configs/starship.toml)

- Vim, [`~/.vimrc`](https://files.le0nardo.dev/configs/_vimrc)

- Rofi, [`~/.config/rofi/config.rasi`](https://files.le0nardo.dev/configs/config.rasi)

- Touchpad, [`/etc/X11/xorg.conf.d/30-touchpad.conf`](https://files.le0nardo.dev/configs/touchpad.conf)

Per avere l'orario nella barra, basta usare uno script che imposta il nome della finestra di dwm.
Per fare ciò, come primo step assicuratevi di avere installato il comando `xsetroot`.

```sh 
# Arch linux

sudo pacman -S xorg-xsetroot

# Void linux

sudo xbps-install xsetroot
```

Mettere il seguente script nel file `/usr/share/dwm/time.sh` e togliere il commento nel file `~/.xinitrc` dove indicato.

```sh
while true; do
	xsetroot -name "$(date '+%H:%M:%S')"
	sleep 1
done
```

Per configurare un fileshare samba, appendete alla fine del file `/etc/fstab` le seguenti istruzioni.

```fstab
# Samba share
//example.com/share	/mnt/privato	cifs	noauto,uid=user,credentials=/home/user/.config/smb/share.conf,x-systemd.automount,x-systemd.device-timeout=10	0 0
```

Successivamente salvare le credenziali nel file `~/.config/smb/share.conf`.

```conf
username=user
password=password
```

## Problemi e domande

Se avete problemi, dubbi o domande in generale sul progetto, aprite una issue nella repository.
