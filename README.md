# minishell


# Setup

Minishelli çalıştırmak için readline kütüphanesini indirmek gerekiyor.

.zshrc dosyanıza aşağıdaki fonksiyonu ekleyin.

```
function brew_install()
{
	cd ~/goinfre
	mkdir homebrew && curl -L https://github.com/Homebrew/brew/tarball/master | tar xz --strip 1 -C homebrew
	cd homebrew/bin && ./brew install readline
}
```
Ardından terminale `brew_install` yazarsanız readline kütüphanesini indirip kuracaktır.

Bu işlemler tamamlandıktan sonra Makefile dosyanızdaki `USERNAME` değişkenini kendi kullanıcı adınız ile değiştirin.

Bu adımlar tamamlandıktan sonra artık programı derleyebilirsiniz.
