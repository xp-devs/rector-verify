<?php
declare(strict_types=1);

use Symplify\EasyCodingStandard\Config\ECSConfig;
use Symplify\EasyCodingStandard\ValueObject\Set\SetList;

return static function (ECSConfig $config): void {
    $config->paths([
        __DIR__ . '/src',
        __DIR__ . '/tests',
    ]);

    $config->sets([
        SetList::PSR_12,
        SetList::STRICT,
    ]);
};
