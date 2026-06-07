#!/usr/bin/env bash
set -euo pipefail

REPO_DIR="/Users/liyunfan/Documents/GitHub/DataStructure_C"
LOG_PREFIX="[auto-commit-push]"

cd "$REPO_DIR"

branch="$(git branch --show-current)"
if [[ -z "$branch" ]]; then
  echo "$LOG_PREFIX not on a branch; skipping"
  exit 0
fi

if ! git rev-parse --abbrev-ref --symbolic-full-name "@{u}" >/dev/null 2>&1; then
  echo "$LOG_PREFIX branch '$branch' has no upstream; skipping"
  exit 1
fi

git add -A

if git diff --cached --quiet; then
  echo "$LOG_PREFIX no changes to commit"
  exit 0
fi

timestamp="$(date '+%Y-%m-%d %H:%M:%S %z')"
git commit -m "chore: auto commit $timestamp"
git push

echo "$LOG_PREFIX committed and pushed changes on $branch"
