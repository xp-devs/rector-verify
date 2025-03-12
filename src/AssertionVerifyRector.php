<?php
declare(strict_types=1);

namespace XpDevs\RectorVerify;

use PhpParser\Node;
use PHPUnit\Framework\TestCase;
use Rector\Rector\AbstractRector;

class AssertionVerifyRector extends AbstractRector
{
    const TWO_ARGS_METHODS_MAP = [
        'assertEquals' => 'toEqual',
        'assertSame' => 'toBe',
    ];

    const ONE_ARG_METHODS_MAP = [
        'assertTrue' => 'toBeTrue',
        'assertFalse' => 'toBeFalse',
    ];

    public function getNodeTypes(): array
    {
        return [Node\Stmt\Expression::class];
    }

    /**
     * @param Node\Stmt\Expression $node
     * @return Node\Stmt\Expression
     */
    public function refactor(Node $node)
    {
        /** @var \ReflectionClass $reflClass */
        $reflClass = $node->getAttribute('scope')->getClassReflection();

        if (!$reflClass->isSubclassOf(TestCase::class)) {
            return $node;
        }

        $expr = $node->expr;
        $isMethodCall = $expr instanceof Node\Expr\StaticCall || $expr instanceof Node\Expr\MethodCall;

        if (!$isMethodCall) {
            return $node;
        }

        foreach (self::TWO_ARGS_METHODS_MAP as $assertion => $expectation) {
            if ($expr->name->name === $assertion) {
                $expect = new Node\Expr\FuncCall(new Node\Name('expect'), [$expr->args[1]]);
                $node->expr = new Node\Expr\MethodCall($expect, new Node\Identifier($expectation), [$expr->args[0]]);

                return $node;
            }
        }

        foreach (self::ONE_ARG_METHODS_MAP as $assertion => $expectation) {
            if ($expr->name->name === $assertion) {
                $expect = new Node\Expr\FuncCall(new Node\Name('expect'), [$expr->args[0]]);
                $node->expr = new Node\Expr\MethodCall($expect, new Node\Identifier($expectation));

                return $node;
            }
        }

        return $node;
    }
}
