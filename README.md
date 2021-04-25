# Are You Sure?

A simple utility that can be used to intercept CLI commands and ask the user
if they are really sure about doing it.

```text
❯ kubectl delete namespace some
DANGER. You are about to execute: 

  kubectl delete namespace some

Are you sure? [Yy] n
Stopping%                                                                                                                                                                                                                                      ~ ─────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────── 2.62s 🕑  k8s.bregenz.a1/b20c05c5-846a-4ebd-b740-84ef38a79a9a ⎈  20:22:10 
❯ kubectl delete namespace some
DANGER. You are about to execute: 

  kubectl delete namespace some

Are you sure? [Yy] Y
namespace "some" deleted

```

## Usage

Suppose you want to intercept all `kubectl delete` commands, add the following to your
`~/.zshrc`, `~/.bashrc` or similar:


```bash
kubectl() {
  if [[ "$@" =~ "delete" ]]; then
      command areyousure "$0" "$@"
  else
      command kubectl "$@"
  fi
}
```

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
2. --install which builds a shell script to wrap command (`areyousure --install kubectl delete`)
3. Colours, Emojis, Fun.
4. Config file
5. Automatic build in GitHub
