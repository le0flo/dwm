# 👨‍💻 Dynamic Window Manager

Un window manager minimale e personalizzabile

## Prerequisiti 

Quà sotto trovate una lista di pacchetti per la compilazione

```sh
sudo pacman -S base-devel xorg-server xorg-xinit xorg-xinput xorg-xsetroot libinput libx11 libxinerama libxft
```

Quà invece una serie di pacchetti necessari per questa build di dwm

```sh
sudo pacman -S kitty feh dex ttf-firacode-nerd
```

## Installazione

```sh
cd dwm
sudo make clean install
```

### Consigliato

Questa personalizzazione di dwm utilizza dmenu per aprire le varie applicazioni, perciò consigio vivamente di scaricare ed installare la giusta versione di [dmenu quì](https://github.com/le0flo/dmenu) prima di continuare con la configurazione del wm.

## Configurazione

Il comando precedente dovrebbe aver installato dwm nel sistema. Per eseguirlo con xinit, inserire il seguente codice nel file `~/.xinitrc`.

```sh
# Compositor
#picom -b

# Sfondi
#feh --no-fehbg --bg-fill "/var/backgrounds/bg.jpg"

# Status
#/var/dwm/time.sh >> /dev/null 2>&1 &

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

PS1="\[\e[01;38;5;106m\]\u\[\e[01;38;5;142m\]@\[\e[01;38;5;143m\]\h \[\e[01;38;5;39m\]\w \[\033[00;0m\]$ "
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
Detto questo, ecco una lista di configurazioni che uso e tengo aggiornate.

- Vim, [`~/.vimrc`](https://files.le0nardo.dev/configs/_vimrc)

- Kitty, [`~/.config/kitty/kitty.conf`](https://files.le0nardo.dev/configs/kitty.conf)

- Picom, [`~/.config/picom/picom.conf`](https://files.le0nardo.dev/configs/picom.conf)

- Touchpad, [`/etc/X11/xorg.conf.d/30-touchpad.conf`](https://files.le0nardo.dev/configs/touchpad.conf)

## Miglioramenti

### Orologio

Mettere il seguente script nel file `/var/dwm/time.sh` e togliere il commento nel file `~/.xinitrc` dove indicato.

```sh
while true; do
	xsetroot -name "⏰ $(date '+%H:%M:%S')"
	sleep 1
done
```

### Sfondi

Creare la cartella `/var/backgrounds` ed intestarla al proprio utente.

```sh
sudo chown -R user:user /var/backgrounds
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

# Problemi e domande

Se avete problemi, dubbi o domande in generale sul progetto, aprite una issue nella repository.
