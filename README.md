# Are You Sure?

![build status](https://github.com/SStorm/areyousure/actions/workflows/build.yml/badge.svg)

A simple utility that can be used to intercept CLI commands and ask the user
if they are really sure about doing it.

```text
$ kubectl delete namespace somenamespace
😮 DANGER. You are about to execute: 

👉 kubectl delete namespace somenamespace

🤔 Are you sure? [Yy] n
👍 Stopping
$ kubectl delete namespace somenamespace
😮 DANGER. You are about to execute: 

👉 kubectl delete namespace somenamespace

🤔 Are you sure? [Yy] y
namespace "somenamespace" deleted
```

## Usage

Suppose you want to intercept all `kubectl delete` commands, add the following to your
`~/.zshrc` / `~/.bashrc` or similar:


```bash
kubectl() {
  if [[ "$@" =~ "delete" ]]; then
      command areyousure "$0" "$@"
  else
      command kubectl "$@"
  fi
}
```

You probably know what you're doing if you're using another shell.

## Installation

You will need cmake, make and a C compiler for this.

```shell
mkdir build
cd build
cmake ..
make
sudo make install # Will copy to /usr/local/bin
```

## TODO

1. Timer (i.e. will execute in 5s)
2. `--install` which builds a shell script to wrap command (`areyousure --install kubectl delete`)
3. Config options / file (i.e. whether to use emojis)
4. Automatic build in GitHub
