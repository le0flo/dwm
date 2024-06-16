# 👨‍💻 Dynamic Window Manager

Per avere la postazione più minimale, dwm era un "no brainer" in quanto personalizzazione, semplicità d'uso e in generale bellezza.
Questa repository è il risultato della mia personalizzazione del progetto.
Insieme a dwm, ho implementato altri programmi fondamentali per l'uso del sistema, come **alacritty** per il terminale, **dmenu** per application launcher e **picom** come compositor delle finestre.

## Prerequisiti

**Premessa**, mi aspetto che questa guida la seguite, avendo sotto mano una installazione di arch completamente pulita.
Io personalmente per risparmiare tempo uso archinstall e ve lo consiglio.
Nel caso gli unici pacchetti da avere insieme al sistema base, è un modo per connettersi al wifi, che sia con **Network Manager** (consigliato) o con **iwd** o addirittura con **wpa_supplicant**, l'importante è che funzioni per voi, **git** e **vim**.  

Prima di procedere all'installazione del window manager, dovrete installare i pacchetti necessari.
Quì avete una lista di pacchetti da installare.

```sh
sudo pacman -S base-devel xorg-server xorg-xinit xorg-xinput xorg-xsetroot libinput libx11 libxinerama libxft
```

In più ci sono i pacchetti non necessari per dwm ma necessari per la seguente configurazione.

```sh
sudo pacman -S  cifs-utils openssh picom feh alacritty ttf-bigblueterminal-nerd
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

### Consigliato

Questa personalizzazione di dwm utilizza dmenu per aprire le varie applicazioni, perciò consigio vivamente di scaricare ed installare la giusta versione di [dmenu quì](https://github.com/le0flo/dmenu) prima di continuare con la configurazione del wm.

# Configurazione

Il comando precedente dovrebbe aver installato dwm nel sistema. Per eseguirlo con xinit, inserire il seguente codice nel file `~/.xinitrc`.

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

Per avviare xinit al login dell'utente, inserite questo snippet di codice nel file `~/.bash_profile`.

```sh
# Avvia X11

if [[ -z $DISPLAY ]] && [[ $(tty) = /dev/tty1 ]]; then
	startx
fi
```

Per avere un prompt carino, sostituisci la seguente linea nel file `~/.bashrc`.

```sh
# Prompt

PS1="\[$(tput setaf 106)\]\u\[$(tput setaf 142)\]@\[$(tput setaf 143)\]\h \[$(tput setaf 39)\]\w \[$(tput sgr0)\]$ "
```

Per risolvere alcuni problemi con programmi (e.g. IntelliJ IDEA), esportate la variabile di ambiente nel file `~/.bashrc`.

```sh
# Variabili di ambiente

export _JAVA_AWT_WM_NONREPARENTING=1
export GIT_EDITOR=vim
```

Alcuni alias utili per miglioramenti nell'esperienza di utilizzo, da inserire nel file `~/.bashrc`.

```sh
# Aliases

alias ls='ls --color=auto'
alias ll='ls --color=auto -al'
alias grep='grep --color=auto'
alias ssh='TERM=xterm-256color ssh'
alias shutdown='shutdown -h now'
```

Io come al solito incito alle persone di studiarsi i programmi e personalizzarseli a mano, ma capisco che non c'è sempre la voglia, parte del motivo per cui ho reso pubblica questa repo.
Perciò ecco una lista di configurazioni che uso e tengo aggiornate.

- Vim, [`~/.vimrc`](https://files.le0nardo.dev/configs/_vimrc)

- Alacritty, [`~/.config/alacritty/alacritty.toml`](https://files.le0nardo.dev/configs/alacritty.toml)

- Picom, [`~/.config/picom/picom.conf`](https://files.le0nardo.dev/configs/picom.conf)

- Touchpad, [`/etc/X11/xorg.conf.d/30-touchpad.conf`](https://files.le0nardo.dev/configs/touchpad.conf)

# Miglioramenti

### Orologio

Mettere il seguente script nel file `/usr/share/dwm/time.sh` e togliere il commento nel file `~/.xinitrc` dove indicato.

```sh
while true; do
	xsetroot -name "$(date '+%H:%M:%S')"
	sleep 1
done
```

### Sfondi

Creare la cartella `/usr/share/backgrounds` ed intestarla al proprio utente.

```sh
sudo chown -R user:user /usr/share/backgrounds
```

Una volta fatto, cercate l'immagine che preferite ed inseritela nella cartella. Per impostare tale immagine come sfondo basta cambiare la linea apposita nel file `~/.xinitrc`.

### Samba share

Per configurare un fileshare samba, appendete alla fine del file `/etc/fstab` le seguenti istruzioni.

```conf
# Samba share
//example.com/share	/mnt/privato	cifs	noauto,uid=user,credentials=/home/user/.config/smb/share.conf,x-systemd.automount,x-systemd.device-timeout=10	0 0
```

Successivamente salvare le credenziali nel file `~/.config/smb/share.conf`.

```conf
username=user
password=password
```

# Software aggiuntivo

Ovviamente la mia configurazione viene anche con il software che uso personalmente. Successivamente lascio un comando e una lista esaustiva dei pacchetti.

```bash
sudo pacman -S unzip zip p7zip fastfetch htop scrot imv mpv mpd lf firefox keepassxc
```

- unzip, zip, p7zip: Vari pacchetti per la gestione degli archivi
- fastfetch, htop, scrot, [pacmixer](https://aur.archlinux.org/pacmixer.git): Strumenti CLI che si occupano di funzionalità base
- imv mpv mpd lf: Viewer di immagini, video, musica e file manager
- firefox: Browser
- keepassxc: Password manager
- [spotify](https://aur.archlinux.org/spotify.git), [spotx](https://github.com/SpotX-Official/SpotX-Bash), Spotify

# Problemi e domande

Se avete problemi, dubbi o domande in generale sul progetto, aprite una issue nella repository.
